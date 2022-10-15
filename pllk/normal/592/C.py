def syt(x,y):
    if y == 0:
        return x
    return syt(y,x%y)

t, w, b = [int(x) for x in raw_input().split(" ")]

z = (w*b)/syt(w,b)

v = 0
v += (t/z)*min(w,b)
v += min(t%z,min(w,b)-1)

s = syt(v,t)
v /= s
t /= s
print str(v) + "/" + str(t)