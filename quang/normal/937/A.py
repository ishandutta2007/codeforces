n = map(int, input())
a = map(int, input().split())
b = set(i for i in a if i > 0)
print (len(b))