k , n , w = map(int , raw_input().split() )
x = w * (w + 1)
x /= 2
x *= k
if x <= n :
    print 0
else :
    print x - n