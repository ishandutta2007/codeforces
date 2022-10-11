import sys
range = xrange
input = sys.stdin.readline

n = int(input())
A = [int(x) for x in input().split() if int(x)!=0]
B = set(A)

print len(B)