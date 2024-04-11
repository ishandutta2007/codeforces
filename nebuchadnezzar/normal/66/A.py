import sys

#file=open("data.in")
#file=sys.stdin

n=int(sys.stdin.readline())

if (n>=-128 & n<=127):
    print('byte')
elif (n>=-32768 & n<=32767):
    print('short')
elif (n>=-2147483648 & n<=2147483647):
    print('int')
elif (n>=-9223372036854775808 & n<=9223372036854775807):
    print('long')
else:
    print('BigInteger')