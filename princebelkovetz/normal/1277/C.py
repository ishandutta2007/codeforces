for _ in range (int(input())):
    s = input()
    ans = []
    for i in range(len(s)):
        if 2 <= i <= len(s) - 2 and s[i - 2: i + 3] == 'twone':
            ans.append(i + 1)
        elif i >= 2 and s[i - 2: i + 1] == 'two':
            ans.append(i)
        elif i <= len(s) - 2 and s[i: i + 3] == 'one':
            ans.append(i + 2)
    print(len(ans))
    print(*ans)