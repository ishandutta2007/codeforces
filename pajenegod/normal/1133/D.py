import sys,io,os
from collections import defaultdict
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

def gcd(x, y):
    """ greatest common divisor of x and y """
    while y:
        x, y = y, x % y
    return x


class Fraction:
    """ A class to represent rational numbers. """

    def __init__(self, num=0, den=1):
        g = gcd(num, den)
        self.num = num // g
        self.den = den // g

    def __add__(self, other):
        num = self.num * other.den + other.num * self.den
        den = self.den * other.den
        g = gcd(num, den)
        return Fraction(num // g, den // g)

    def __sub__(self, other):
        num = self.num * other.den - other.num * self.den
        den = self.den * other.den
        g = gcd(num, den)
        return Fraction(num // g, den // g)

    def __mul__(self, other):
        num = self.num * other.num
        den = self.den * other.den
        g = gcd(num, den)
        return Fraction(num // g, den // g)

    def __truediv__(self, other):
        num = self.num * other.den
        den = self.den * other.num
        g = gcd(num, den)
        return Fraction(num // g, den // g)

    def __floordiv__(self, other):
        return (self.num * other.den) // (self.den * other.num)

    def __pow__(self, other):
        return Fraction(self.num**other, self.den**other)

    def __bool__(self):
        return bool(self.num)

    def __float__(self):
        return self.num / self.den

    def __abs__(self):
        return self if self.num >= 0 else Fraction(-self.num, self.den)

    def __neg__(self):
        return Fraction(-self.num, self.den)

    def __round__(self, ndigits=None):
        return round(self.num / self.den, ndigits)

    def __copy__(self):
        return Fraction(self.num, self.den)

    def __hash__(self):
        return hash((self.num, self.den))

    def __eq__(self, other):
        return (self.num, self.den) == (other.num, other.den)

    def __ne__(self, other):
        return not (self == other)

    def __ge__(self, other):
        pass

    def __gt__(self, other):
        pass

    def __le__(self, other):
        pass

    def __lt__(self, other):
        pass

    def from_float(self, num):
        pass

    def limit_denominator(self, limit):
        pass


def main():
    n = int(input())
    A = [int(x) for x in input().split()]
    B = [int(x) for x in input().split()]

    votes = defaultdict(int)
    g = 0
    for i in range(n):
        a = A[i]
        b = B[i]
        if b == 0 and a == 0:
            g += 1
        elif b == 0:
            votes[Fraction(0)] += 1
        elif a == 0:
            pass
        else:
            votes[Fraction(a, b)] += 1
    print(max([votes[v] for v in votes] or [0]) + g)


if __name__ == '__main__':
    main()