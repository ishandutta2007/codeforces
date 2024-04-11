import sys
range = xrange
input = raw_input

def mapper(a):
    return [ord(c) - ord('0') for c in a]
def remapper(a):
    return ''.join(chr(c + ord('0')) for c in a)

a = mapper(input())
b = mapper(input())
a.sort()

m = len(a)
if m < len(b):
    print remapper(a)[::-1]
    sys.exit()

DP = [-2]*(1 << m)
def best(mask, i):
    if i == m:
        return 0
    if DP[mask] > -2:
        return DP[mask]
    ans = -1
    for j in reversed(range(m)):
        newmask = mask | (1 << j)
        if mask != newmask and (a[j] or i):
            if a[j] == b[i]:
                x = best(newmask, i + 1)
                if x >= 0:
                    ans = a[j] * 10 ** (m - 1 - i) + x
                    break
            elif a[j] < b[i]:
                ans = a[j]
                for k in reversed(range(m)):
                    if not newmask & (1 << k):
                        ans = 10 * ans + a[k]
                break
    DP[mask] = ans
    return ans

print best(0, 0)