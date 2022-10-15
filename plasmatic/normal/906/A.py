input=__import__('sys').stdin.readline
left,bad=set([chr(i+ord('a')) for i in range(26)]),0
q=int(input())
for i in range(q-1):
    op,s = input().split()
    bad += len(left)==1and op!='.'
    if op=='!': left=left&set(s)
    else: left=left-set(s)
print(bad)