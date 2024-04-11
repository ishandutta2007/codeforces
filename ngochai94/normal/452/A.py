n=input()
s=raw_input()
for i in ["vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"]:
    if len(i)==n:
        can=True
        for j in range(n):
            if s[j]!='.':
                if s[j]!=i[j]:
                    can=False
                    break
        if can:
            print i