from math import atan2, pi

EPS = 0.00000001


def eq(a, b):
    return abs(a - b) < EPS


class Vector:
    def __init__(self, x2, y2, x1=0, y1=0):
        self.x = (x2 - x1)
        self.y = y2 - y1
        self.s = (self.x ** 2 + self.y ** 2) ** 0.5

    def __add__(self, other):
        return Vector(self.x + other.x, self.y + other.y)

    def __sub__(self, other):
        return Vector(self.x - other.x, self.y - other.y)

    def mul_k(self, k):
        self.x *= k
        self.y *= k

    def mul_kk(self, k):
        return Vector(self.x * k, self.y * k)

    def rotate(self):
        return Vector(-self.y, self.x)

    def rotate2(self):
        return self.rotate().rotate().rotate()

    def reverseee(self):
        return Vector(-self.x, -self.y)

    def __mul__(self, other):
        return self.x * other.x + self.y * other.y

    def vectormul(self, other):
        return self.x * other.y - self.y * other.x

    def get_angle(self, other):
        return atan2(self.vectormul(other), self * other)

    def norm(self):
        if self.s == 0:
            return Vector(self.x, self.y)
        return Vector(self.x / self.s, self.y / self.s)

    def __str__(self):
        return f'{self.x} {self.y}'

    def middle(self, point):
        return Vector((self.x + point.x) / 2, (self.y + point.y) / 2)


class Line:
    def __init__(self, point=None, vector=None, point2=None, a=None, b=None, c=None):
        if a is not None:
            self.v = Vector(a, b).rotate()
            self.p = Vector(a, b)
            self.p.mul_k(-c / (a ** 2 + b ** 2))
            self.A = a
            self.B = b
            self.C = c
            return
        if vector is None:
            vector = point2 - point
        self.p = point
        self.v = vector
        self.A = self.v.y
        self.B = -self.v.x
        self.C = - self.A * self.p.x - self.p.y * self.B

    def get_abc(self):
        return self.A, self.B, self.C

    def __str__(self):
        return str(self.A) + ' ' + str(self.B) + ' ' + str(self.C)

    def check(self, point):
        return eq(- point.x * self.A - self.B * point.y, self.C)

    def get_s_from_point(self, point):
        v = self.v.norm()
        v2 = point - self.p
        a = v * v2
        v.mul_k(a)
        v3 = v + self.p
        s = v3 - point
        return s.s

    def get_bisect(self, line):
        return Line(point=self.get_peresech(line)[1], vector=self.v.norm() + line.v.norm())

    def get_proection(self, point):
        v = self.v.norm()
        v2 = point - self.p
        a = v * v2
        v.mul_k(a)
        v3 = v + self.p
        return v3

    def get_paral_line(self, le):
        v = self.v.norm().rotate()
        v.mul_k(le)
        return Line(point=self.p + v, vector=self.v)

    def get_peresech(self, lin):
        u = lin.v.rotate()
        a = self.v * u
        if eq(a, 0):
            if eq(self.get_s_from_point(lin.p), 0):
                return (2,)
            return (0,)
        t = ((lin.p - self.p) * u) / (self.v * u)
        v = Vector(self.v.x, self.v.y)
        v.mul_k(t)
        return (1, self.p + v)

    def get_mirror(self, point):
        v = self.v.norm()
        v2 = point - self.p
        a = v * v2
        v.mul_k(a)
        v3 = v + self.p
        s = v3 - point
        return s + v3


def is_on_line(v1, v2):
    return eq(v1.vectormul(v2), 0)


def is_on_luch(v1, v2):
    return eq(v1.get_angle(v2), 0)


def is_on_otr(v1, v2, v3, v4):
    return eq(v1.get_angle(v2), 0) and eq(v3.get_angle(v4), 0)


def get_s_from_luch(xp, yp, x1, y1, x2, y2):
    v = Vector(x2, y2, x1, y1).norm()
    v2 = Vector(xp, yp, x1, y1)
    a = v * v2
    v1 = Vector(x2, y2, x1, y1)
    v.mul_k(a)
    v3 = v + Vector(x1, y1)
    xh, yh = v3.x, v3.y
    v4 = Vector(xh, yh, x1, y1)
    b = v1.get_angle(v4)
    if eq(b, 0):
        se = v3 - Vector(xp, yp)
        return se.s
    else:
        return (Vector(x1, y1) - Vector(xp, yp)).s


def get_s_from_otr(xp, yp, x1, y1, x2, y2):
    return max(get_s_from_luch(xp, yp, x1, y1, x2, y2), get_s_from_luch(xp, yp, x2, y2, x1, y1))


def get_s_from_line(xp, yp, x1, y1, x2, y2):
    v = Vector(x2, y2, x1, y1).norm()
    v2 = Vector(xp, yp, x1, y1)
    a = v * v2
    return a


def peresec_otr(x1, y1, x2, y2, x3, y3, x4, y4):
    AB = Vector(x2, y2, x1, y1)
    CD = Vector(x4, y4, x3, y3)
    AC = Vector(x3, y3, x1, y1)
    AD = Vector(x4, y4, x1, y1)
    CA = Vector(x1, y1, x3, y3)
    CB = Vector(x2, y2, x3, y3)
    yg1 = AB.get_angle(AD)
    yg2 = AB.get_angle(AC)
    yg3 = CD.get_angle(CA)
    yg4 = CD.get_angle(CB)
    flag = False
    if (yg1 < 0 and yg2 < 0) or (yg1 > 0 and yg2 > 0):
        flag = True
    if (yg3 < 0 and yg4 < 0) or (yg3 > 0 and yg4 > 0):
        flag = True
    if max(min(x1, x2), min(x3, x4)) > min(max(x1, x2), max(x3, x4)):
        flag = True
    if max(min(y1, y2), min(y3, y4)) > min(max(y1, y2), max(y3, y4)):
        flag = True
    return not flag


def get_s_from_otr_to_otr(x1, y1, x2, y2, x3, y3, x4, y4):
    if peresec_otr(x1, y1, x2, y2, x3, y3, x4, y4):
        return 0
    return min(get_s_from_otr(x1, y1, x3, y3, x4, y4), get_s_from_otr(x2, y2, x3, y3, x4, y4),
               get_s_from_otr(x3, y3, x1, y1, x2, y2), get_s_from_otr(x4, y4, x1, y1, x2, y2))


def main():
    px, py, vx, vy, a, b, c, d = map(int, input().split())
    P = Vector(px, py)
    V = Vector(vx, vy).norm()
    A = V.mul_kk(b) + P
    B = V.mul_kk(a/2).rotate() + P
    C = V.mul_kk(c/2).rotate() + P
    D = C + V.rotate().rotate().mul_kk(d)
    E = D + V.rotate2().mul_kk(c)
    F = P + V.rotate2().mul_kk(c/2)
    G = P + V.rotate2().mul_kk(a/2)
    print(A, B, C, D, E, F, G, sep='\n')


main()