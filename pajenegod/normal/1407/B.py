# not my code
# https://codeforces.com/contest/1407/submission/92248591
 
# Author : raj1307 - Raj Singh
# Date   : 08.09.2020
 
import sys
 
input = sys.stdin.readline 
 
def gcd(x, y):
    if not x:
        return y
    while y:
        x, y = y, x % y
    return x
    
def main():
    for _ in range(int(input())):
        n=int(input())
        a=[int(x) for x in input().split()]
        f=[0]*(n+5)
 
        a.sort(reverse=True)
 
        ans=[a[0]]
        f[0]=1
        g=a[0]
 
        while len(ans)!=n:
            mx=0
            pos=-1
 
            for i in range(n):
                if f[i]==0:
                    if gcd(g,a[i])>mx:
                        mx=gcd(g,a[i])
                        pos=i
            f[pos]=1
            ans.append(a[pos])
            g=gcd(g,a[pos])
        print ' '.join(str(x) for x in ans)
main()