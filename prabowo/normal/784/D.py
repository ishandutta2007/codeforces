d = {
  '0': '8',
  '1': -1,
  '2': -1,
  '3': '3',
  '4': '6',
  '5': '9',
  '6': '4',
  '8': '0',
  '7': '7',
  '9': '5',
}

s = input()
print("Yes" if list(s)[::-1] == list([d[c] for c in s]) else "No")