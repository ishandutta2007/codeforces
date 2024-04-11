import sys
input = raw_input

t = int(input())
for _ in range(t):
    W,H = [int(x) for x in input().split()]

    x1,y1,x2,y2 = [int(x) for x in input().split()]
    
    w,h = [int(x) for x in input().split()]

    cur_hspace = max(x1, W - x2)
    cur_vspace = max(y1, H - y2) 

    max_hspace = W - (x2 - x1)
    max_vspace = H - (y2 - y1)

    if max_hspace < w and max_vspace < h:
        print -1
    elif max_hspace >= w and max_vspace >= h:
        print max(0, min(w - cur_hspace, h - cur_vspace))
    elif max_hspace >= w:
        print max(0, w - cur_hspace)
    else:
        print max(0, h - cur_vspace)