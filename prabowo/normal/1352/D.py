import sys


input()
for candies in sys.stdin.readlines()[1::2]:
    candies = [int(c) for c in candies.split()]
    a, b = 0, 0
    idxA, idxB, move = 0, len(candies) - 1, 0

    eaten = 0
    while idxA <= idxB:
        lastEaten = eaten
        eaten = 0
        if move & 1 == 0:
            while idxA <= idxB and eaten <= lastEaten:
                a += candies[idxA]
                eaten += candies[idxA]
                idxA += 1
        else:
            while idxB >= idxA and eaten <= lastEaten:
                b += candies[idxB]
                eaten += candies[idxB]
                idxB -= 1

        move += 1

    print(move, a, b)