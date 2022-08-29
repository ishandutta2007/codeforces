def round_up(n):
    return n if n % 2 == 0 else n + 1

A = raw_input()
B = raw_input()

print 'YES' if round_up(A.count('1')) >= B.count('1') else 'NO'