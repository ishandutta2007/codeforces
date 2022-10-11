input = raw_input
range = xrange

n,m = [int(x) for x in input().split()]
ip2name = {}
name2ip = {}
for i in range(n):
    name,ip = input().split()
    ip2name[ip] = name
    name2ip[name] = ip

for j in range(m):
    com,ip= input().split()
    ip = ip[:-1]
    print ''.join([com,' ',ip,'; #',ip2name[ip]])