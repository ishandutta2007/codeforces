a = tuple(map(int, input().split()))
b = tuple(map(int, input().split()))
c = tuple(map(int, input().split()))
d = tuple(map(int, input().split()))


def check(el1, el2):
    if el1[0][0] > el2[1][1] and el1[1][1] > el2[0][0]:
        return 1
    if el2[0][0] > el1[1][1] and el2[1][1] > el1[0][0]:
        return 2
    return 0


def check2(el):
    ans = 5
    cd = [(c, d), (d, c)]
    for el2 in cd:
        if check(el, el2) == 2:
            return 2
        ans = min(ans, check(el, el2))
    return ans


def main():
    ans = 5
    aw = [(a, b), (b, a)]
    for el in aw:
        if check2(el) == 1:
            return print('Team 1')
        ans = min(ans, check2(el))
    if ans == 0:
        print("Draw")
    else:
        print("Team 2")


main()