ls = [int(input()) for i in range(4)]
A = (ls[0] ^ ls[1])
B = (ls[2] or ls[3])
C = (ls[1] and ls[2])
D = (ls[0] ^ ls[3])

print( (A and B) ^ (C or D) )