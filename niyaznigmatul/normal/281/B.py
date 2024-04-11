
class Fraction:
  def __init__(self, x, y):
    self.x = x
    self.y = y
  
  def __sub__(self, a):
    return Fraction(self.x * a.y - a.x * self.y, self.y * a.y)
  
  def __lt__(self, a):
    return self.x * a.y < self.y * a.x
    
  def __abs__(self):
    if self.x < 0:
      return Fraction(-self.x, self.y)
    return self
  def __str__(self):
    return str(self.x) + '/' + str(self.y)
    
x, y, n = map(int, raw_input().split())
f = Fraction(x, y)
dif = None
for i in range(1, n + 1):
  m = x * i // y
  for d in [m, m + 1]:
    g = Fraction(d, i)
    if dif is None or abs(f - g) < dif:
      dif = abs(f - g)
      ans = g
print(ans)