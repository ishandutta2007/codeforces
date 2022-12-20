N = input()
d = list()

def read2(i):
    try:
        m = 1/(N-i)
    except:
        return
    d.append(raw_input().split())
    read2(i+1)

read2(0)

def f3(k,i,j):
    try:
        m = 1/(N-j)
    except:
        return
    d[i][j] = min(int(d[i][j]),int(d[i][k])+int(d[k][j]))
    f3(k,i,j+1)

def f2(k,i):
    try:
        m = 1/(N-i)
    except:
        return
    f3(k,i,0)
    f2(k,i+1)

def f1(k):
    try:
        m = 1/(N-k)
    except:
        return
    f2(k,0)
    f1(k+1)

f1(0)

ans = 0

def a2(i,j):
    try:
        m = 1/(N-j)
    except:
        return
    global ans
    ans = max(ans,d[i][j])
    a2(i,j+1)

def a1(i):
    try:
        m = 1/(N-i)
    except:
        return
    a2(i,0)
    a1(i+1)

a1(0)
print ans