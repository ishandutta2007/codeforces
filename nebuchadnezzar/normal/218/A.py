import sys

n, k = map(int, raw_input().strip().split())

mas = map(int, raw_input().strip().split())

ans = ""
count = 0
for i in xrange(2 * n + 1):
    #print "!", i
    if(i % 2 == 1 and count < k):
        #print "@", i
        if(mas[i - 1] + 1 < mas[i] and mas[i] > mas[i + 1] + 1):
            #print "#", i
            count += 1
            mas[i] -= 1
    sys.stdout.write(str(mas[i]) + " ")