fin = 0
strs = "abcdefghijklmnopqrstuvwxyz"
idx = 0


def YESNO(flg):
    global fin
    if not fin:
        print("YES" if flg else "NO")
    if not flg:
        fin = 1


def solve(N, M, A, B):
    global idx
    global strs

    def fillhor(i, j):
        global answer
        assert 0 <= i < N and 0 <= j < M - 1
        answer[i][j] = "<"
        answer[i][j + 1] = ">"

    def fillver(i, j):
        global answer
        assert 0 <= i < N - 1 and 0 <= j < M
        answer[i][j] = "^"
        answer[i + 1][j] = "v"

    if N % 2 == M % 2 == 0:
        square_num = (A + 1) // 2 + (B + 1) // 2
        if (N * M) // 4 < square_num:
            YESNO(False)
        else:
            YESNO(True)
            for i in range(0, N, 2):
                for j in range(0, M, 2):
                    if A:
                        fillhor(i, j)
                        A -= 1
                        if A:
                            fillhor(i + 1, j)
                            A -= 1
                    elif B:
                        fillver(i, j)
                        B -= 1
                        if B:
                            fillver(i, j + 1)
                            B -= 1
    elif N % 2 == 0 and M % 2 == 1:
        j = M - 1
        for i in range(0, N, 2):
            if B:
                fillver(i, j)
                B -= 1
        solve(N, M - 1, A, B)
    elif N % 2 == 1 and M % 2 == 0:
        i = N - 1
        for j in range(0, M, 2):
            if A:
                fillhor(i, j)
                A -= 1
        solve(N - 1, M, A, B)
    else:
        if N == 1 and M == 1:
            YESNO(A == 0 and B == 0)
        elif N == 1 and M != 1:
            YESNO(2 * A <= M and B == 0)
            for i in range(0, M, 2):
                if A:
                    fillhor(0, i)
                    A -= 1
        elif N != 1 and M == 1:
            YESNO(2 * B <= N and A == 0)
            for i in range(0, N, 2):
                if B:
                    fillver(i, 0)
                    B -= 1
        else:
            j = M - 1
            for i in range(0, N - 1, 2):
                if B:
                    fillver(i, j)
                    B -= 1
            if B % 2 == 1:
                fillver(N - 2, M - 3)
                B -= 1
                if A:
                    fillhor(N - 3, M - 3)
                    A -= 1
                if A:
                    fillhor(N - 1, M - 2)
                    A -= 1
            else:
                if A:
                    fillhor(N - 1, M - 3)
                    A -= 1
                if B >= 2:
                    fillver(N - 3, M - 3)
                    fillver(N - 3, M - 2)
                    B -= 2
                else:
                    if A:
                        fillhor(N - 3, M - 3)
                        A -= 1
                    if A:
                        fillhor(N - 2, M - 3)
                        A -= 1

            j = M - 3
            for i in range(0, N - 3, 2):
                if B:
                    fillver(i, j)
                    B -= 1
                    if B:
                        fillver(i, j + 1)
                        B -= 1
                elif A:
                    fillhor(i, j)
                    A -= 1
                    if A:
                        fillhor(i + 1, j)
                        A -= 1
            if M > 3:
                solve(N, M - 3, A, B)
            else:
                YESNO(A == 0 and B == 0)


t = int(input())
for _ in range(t):
    fin = 0
    idx = 0
    N, M, A = map(int, input().split())
    B = N * M // 2 - A
    answer = [["."] * M for _ in range(N)]
    answer2 = [["."] * M for _ in range(N)]
    solve(N, M, A, B)
    if not fin:
        for i in range(N):
            for j in range(M):
                if answer[i][j] == "<":
                    while strs[idx] == answer2[i - 1][j] or (j + 1 < M and strs[idx] == answer2[i - 1][j + 1]) or (j - 1 >= 0 and strs[idx] == answer2[i][j - 1])  or (j + 2 < M and strs[idx] == answer2[i - 1][j + 2]):
                        idx += 1
                        idx %= 26
                    answer2[i][j] = answer2[i][j + 1] = strs[idx]
                elif answer[i][j] == "^":
                    while strs[idx] == answer2[i - 1][j] or (j + 1 < M and strs[idx] == answer2[i][j + 1]) or (j - 1 >= 0 and strs[idx] == answer2[i][j - 1]):
                        idx += 1
                        idx %= 26
                    answer2[i][j] = answer2[i + 1][j] = strs[idx]

        for row in answer2:
            print("".join(row))