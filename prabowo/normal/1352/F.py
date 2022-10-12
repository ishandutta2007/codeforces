for tc in range(int(input())):
    n0, n1, n2 = [int(s) for s in input().split()]
    print('0'*(n0+1) + '1'*(n2+1) + ''.join([str(i&1) for i in range(n1-1)]) if n1 > 0 else '0' * (n0 and n0+1) + '1' * (n2 and n2+1))