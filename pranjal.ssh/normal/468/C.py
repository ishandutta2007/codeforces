a = int(input())
y = (10**19)*20*45
y = y % a
print (a-y,a-y+10**20-1)