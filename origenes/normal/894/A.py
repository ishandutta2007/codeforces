s = input()
Len = len(s)
cnt = 0
for i in range(Len):
    if s[i] == 'Q':
        for j in range(i + 1, Len):
            if s[j] == 'A':
                for k in range(j + 1, Len):
                    if s[k] == 'Q':
                        cnt += 1
print(cnt)