t = int(input())
def main():
 n = int(input())
 s = input()[::-1]
 hn = n // 2
 if s[:hn+1] == ')'*(hn+1):
  print("Yes")
 else:
  print("No")

for _ in range(t):
 main()