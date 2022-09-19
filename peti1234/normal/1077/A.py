w=int(input())
for tc in range(w):
    a, b, k=map(int,input().split())
    if k%2==0:
        print(k//2*(a-b))
    else:
        print(k//2*(a-b)+a)