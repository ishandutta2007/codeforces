from sys import stdin,stdout
input=stdin.readline
print=stdout.write
for _ in range(int(input())):
    n,x = map (int,input().split())
    a=[int(i) for i in input().split()]
    a.sort(reverse=True)
    t = counter = 0
    for i in range (n):
        t+=a[i]
        if t/(counter+1)>=x:
            counter += 1
        else:
            break
    print(str(counter)+'\n')