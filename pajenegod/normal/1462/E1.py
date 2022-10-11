# Not my code
# https://codeforces.com/contest/1462/submission/101312768
import sys
input = lambda: sys.stdin.readline().rstrip()

from bisect import bisect_right
def main():
    for _ in range(int(input())):
        n=int(input())
        a=sorted(list(map(int,input().split())))
        s=0
        for i in range(n-2):
            t=bisect_right(a,a[i]+2)
            x=t-i-1
            s+=x*(x-1)//2
        print(s)
        

main()