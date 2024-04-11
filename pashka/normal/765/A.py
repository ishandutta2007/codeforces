n = int(input())
places = set()
start = input()
places.add(start)
for i in range(n):
    for s in input().split("->"):
        if s in places:
            places.remove(s)
        else:
            places.add(s)
for place in places:
    if place == start:
        print("home")
    else:
        print("contest")