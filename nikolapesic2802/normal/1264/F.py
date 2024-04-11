pr=15*10**8
dd=10**9
ic=pow(584177449,4*10**8-1,dd)
n,a,d=map(int,raw_input().split())
print (ic*a)%dd*pr+1,(ic*d)%dd*pr