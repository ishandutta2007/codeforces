import sys

for line in sys.stdin:
  parts = line.strip().split()
  print int(parts[0]) + int(parts[1])