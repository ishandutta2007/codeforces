import sys
range = xrange
input = raw_input
 
A = [+(c == '1') for c in sys.stdin.read()]
A.pop()
n = len(A)
 
cumA = [0]
for a in A:
    cumA.append(cumA[-1] + a)
 
frac_limit = 200
 
# Calculate number of intervals with 1/frac ones, 1 <= frac < frac_limit
big = n + n
counter = [0]*big
last_used = [0]*big
 
combs = 0.0
t = 0
for frac in range(1, frac_limit):
    tmp = 0
    for i in range(frac):
        x = 0
        while i <= n:
            c = cumA[i] - x
            if last_used[c] != t:
                last_used[c] = t
                counter[c] = 0
            tmp += counter[c]
            counter[c] += 1
            i += frac
            x += 1
        t += 1
    combs += tmp
 
# Calculate number of intervals with 1/frac ones, frac >= frac_limit
ones = [i for i in range(n) if A[i]]
ones.append(n)
 
one_ind = 0
a = len(ones) - 1
for i in range(n):
    b = one_ind + (n - i)//frac_limit
    tmp = 0
    for j in range(one_ind, a if a < b else b):
        count = j - one_ind + 1
        interval = ones[j] - i + 1

        uncovered_interval = count * frac_limit
        if interval < uncovered_interval:
            interval = uncovered_interval
        else:
            interval += (count - interval) % count
        
        hits = 1 + (ones[j + 1] - i - interval) // count
        if hits > 0:
            tmp += hits
    combs += tmp
    one_ind += A[i]

 
print int(combs)