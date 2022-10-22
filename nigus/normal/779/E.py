


def OP(i,j,op):
    if op == "AND":
        return i & j
    if op == "OR":
        return i | j
    if op == "XOR":
        return i ^ j
    return 0

def totbit(i,test):
    ans = 0
    for j in range(0,len(ops)):
        a = ops[j][0]
        b = ops[j][1]
        op = ops[j][2]
        if a == "?":
            x = test
        else:
            if a in M:
                x = int(M[a][i])
            else:
                x = OL[OD[a]]
        if b == "?":
            y = test
        else:
            if b in M:
                y = int(M[b][i])
            else:
                y = OL[OD[b]]
        ans += OP(x,y,op)
        OL[j] = OP(x,y,op)
    return ans
        


ops = []
[n,m] = list(map(int , input().split()))
M = dict()
OL = []
OD = dict()
for i in range(0,n):
    inp = input().split()
    a = inp[0]
    if len(inp) == 3:
        b = inp[2]
        M[a] = b
    else:
        a = inp[2]
        b = inp[4]
        op = inp[3]
        OD[inp[0]] = len(OL)
        OL.append(0)
        ops.append([a,b,op])
mi = ""
ma = ""

for i in range(0,m):
    b0 = totbit(i,0)
    b1 = totbit(i,1)
    if b0 >= b1:
        ma += "0"
    else:
        ma += "1"
    if b0 <= b1:
        mi += "0"
    else:
        mi += "1"
print(mi)
print(ma)