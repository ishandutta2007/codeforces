n, t = [int(x) for x in raw_input().strip().split(" ")]
a = 10**n-1
while True:
    if a < 1 or len(str(a)) <> n:
        print "-1"
        exit()
    if a%t == 0:
        print a
        exit()
    a -= 1