for i in range(5):
  s=input()
  if '1' in s:
    print(abs(i-2)+abs(s.index('1')//2-2))