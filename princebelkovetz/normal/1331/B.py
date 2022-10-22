from sys import stdin, stdout
a=int(stdin.readline())
i=1
while True:
    i+=1
    if a%i==0:
        break
stdout.write(str(i)+str(a//i))