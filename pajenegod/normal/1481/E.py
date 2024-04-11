import sys, collections
range = xrange
input = raw_input
 
n = int(input())
A = [int(x) for x in input().split()]
 
colors = len(set(A))
 
mapper = collections.defaultdict(lambda:colors - 1 - len(mapper))
A = [mapper[a] for a in A[::-1]][::-1]
 
buckets = [[] for _ in range(colors)]
for i in range(n):
    buckets[A[i]].append(i)

suffixmin = A[:]
for i in reversed(range(n - 1)):
    suffixmin[i] = min(suffixmin[i], suffixmin[i + 1])
 
DP0 = [0] * (colors + 1)
DP1 = [0] * (colors + 1)
 
for color in range(colors):
    bucket = buckets[color]
 
    # Go over the count of books with color "color" to be moved to the end
    for books_moved in range(len(bucket) + 1):
        books_not_moved = len(bucket) - books_moved
 
        if books_not_moved == 0:
            prev_color = color - 1
        else:
            prev_color = suffixmin[bucket[-books_not_moved]] - 1
        
        
        if books_moved == 0 or books_not_moved == 0:
            DP0[color] = max(DP0[color], DP0[prev_color] + books_not_moved)
        
        if books_not_moved == 0:
            DP1[color] = max(DP1[color], DP1[prev_color] + books_not_moved)
        else:
            DP1[color] = max(DP1[color], DP0[prev_color] + books_not_moved)
 
print n - max(DP0[colors - 1], DP1[colors - 1])