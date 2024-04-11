import sys
range = xrange
input = raw_input

h,w,P = [int(x) for x in input().split()]
S = [int(x) for x in input().split()]

board = []
inp = sys.stdin.read()
for ind in range(len(inp)):
    c = ord(inp[ind])
    if c==46:
        board.append(-1)
    elif 49<=c<=58:
        board.append(c-49)
    elif c==35:
        board.append(-2)

new_castles = [[] for _ in range(P)]
new_castles_ind = [0 for _ in range(P)]

for pos in range(h*w):
    if board[pos]>=0:
        new_castles[board[pos]].append((pos,0))

player_Q = [p for p in range(P) if new_castles[p]]
player_Q_ind = 0

while player_Q_ind != len(player_Q):
    p = player_Q[player_Q_ind]
    player_Q_ind += 1
    Q = new_castles[p]
    Q_ind = new_castles_ind[p]

    goal = Q[Q_ind][1] + S[p]
    while Q_ind != len(Q) and Q[Q_ind][1] != goal:
        pos,moves = Q[Q_ind]
        Q_ind += 1
        y = pos//w
        x = pos - y*w
        
        if 0<x and board[pos-1]==-1:
            board[pos-1]=p
            Q.append((pos-1,moves+1))
        
        if x<w-1 and board[pos+1]==-1:
            board[pos+1]=p
            Q.append((pos+1,moves+1))
    
        if 0<y and board[pos-w]==-1:
            board[pos-w]=p
            Q.append((pos-w,moves+1))
        
        if y<h-1 and board[pos+w]==-1:
            board[pos+w]=p
            Q.append((pos+w,moves+1))
    if Q_ind != len(Q):
        player_Q.append(p)
        new_castles_ind[p] = Q_ind

count = [0 for _ in range(P)]
for x in board:
    if x >= 0:
        count[x] += 1
print ' '.join(str(x) for x in count)