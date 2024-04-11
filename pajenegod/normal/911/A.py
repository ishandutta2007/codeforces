input = raw_input

n = int(input())
A = [int(x) for x in input().split()]

x = min(A)
B = [i for i in range(n) if A[i] == x]

print min(B[j] - B[j - 1] for j in range(1, len(B)))