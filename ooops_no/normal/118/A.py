a=input().lower()
g=""
for j in a:
    if j=="a" or j=="o" or j=="y" or j=="e" or j=="u" or j=="i":
        continue
    else:
        g+="."+j
print(g)