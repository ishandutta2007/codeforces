import sys
from collections import Counter

N = int(raw_input())
calls = map(int, raw_input().split())
assert len(calls) == N
freq = Counter(calls)
chats = 0

for id in freq:
    if id == 0:
        continue
    elif freq[id] > 2:
        print -1
        sys.exit()
    elif freq[id] == 2:
        chats += 1

print chats