import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    S = [ord(c) - ord('a') for c in input()]
    T = [ord(c) - ord('a') for c in input()]

    n = len(S)
    m = len(T)

    buckets = [[n] for _ in range(26)]
    for i in reversed(range(n)):
        buckets[S[i]].append(i)

    for l in range(0, m + 1):
        # dp[i][j] = min k such that S[:k] can be used to match T[:i], T[l:j]
        A = l + 1
        B = m - l + 1

        dp = [n]*(A * B)
        buckets_copy = [list(b) for b in buckets]
        last_letter = [b[-1] for b in buckets_copy]
        
        state_buckets = [[] for _ in range(n + 2)]
        state_buckets[-1].append(0)
        for i in range(-1, n):
            if i >= 0: 
                buckets_copy[S[i]].pop()
                last_letter[S[i]] = buckets_copy[S[i]][-1]
            
            for ind in state_buckets[i]:
                if dp[ind] > i:
                    dp[ind] = i
                    
                    b,a = divmod(ind, A)
                    if a < l:
                        state_buckets[last_letter[T[a]]].append(ind + 1)
                    if l + b < m:
                        state_buckets[last_letter[T[l + b]]].append(ind + A)

        if dp[-1] != n:
            print 'YES'
            break
    else:
        print 'NO'