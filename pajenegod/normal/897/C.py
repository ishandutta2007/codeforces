import sys


f0 = "What are you doing at the end of the world? Are you busy? Will you save us?"
part1 = "What are you doing while sending \""
part2 = "\"? Are you busy? Will you send \""
part3 = "\"?"
a = len(part1)
b = len(part2)
c = len(part3)
biggest = 10**18+2
len_fn = [0]*(10**5+10)
len_fn[0] = len(f0)
for i in range(1,10**5+1):
    len_fn[i] = a+b+c+2*len_fn[i-1]
    if len_fn[i]>biggest:
        len_fn[i] = biggest


q = int(input())
for _ in range(q):
    n,k = [int(x) for x in input().split()]
    k-=1
    while n>0:
        if k<a:
            sys.stdout.write(part1[k])
            break
        elif k<a+len_fn[n-1]:
            k -= a
            n -= 1

        elif k<a+len_fn[n-1] + b:
            sys.stdout.write(part2[k-a-len_fn[n-1]])
            break
        elif k<a+2*len_fn[n-1] + b:
            k-= a + len_fn[n-1] + b
            n-=1
        elif k<a+2*len_fn[n-1] + b + c:
            sys.stdout.write(part3[k-a-2*len_fn[n-1]-b])
            break
        else:
            sys.stdout.write('.')
            break
    else:
        if k<len(f0):
            sys.stdout.write(f0[k])
        else:
            sys.stdout.write('.')