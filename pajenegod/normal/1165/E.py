n = int(input())
print(sum(ai % 998244353 * bi for ai, bi in zip(sorted((x*(i+1)*(n-i) for i,x in enumerate(map(int,input().split())))), sorted(map(int,input().split()), reverse = True))) % 998244353)