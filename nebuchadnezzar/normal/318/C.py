x, y, m = map(int, raw_input().strip().split())

if(x >= m or y >= m):
    print(0)
elif(x <= 0 and y <= 0):
    print(-1)
else:
    ans = 0
    if(x > y):
        mem = y
        y = x
        x = mem
    
        
    while(True):
        mem = y
            
        ans += (y - x + y) / y
        y = x + ((y - x + y) / y) * y
        x = mem
        if(y >= m):
            print(ans)
            break