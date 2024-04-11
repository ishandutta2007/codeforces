from sys import stdin, stdout


def check(lim, arr):
    if int(arr[0]) < lim or int(arr[1]) < lim:
        return False
    return max(0, int(arr[0]) - lim) + max(0, int(arr[1]) - lim) + int(arr[2]) >= lim


if __name__ == "__main__":

    q = int(stdin.readline())
    while q > 0:
        q = q - 1
        arr = stdin.readline().split(" ")
        res = -1
        step = (1 << 30)
        while step > 0:
            if check(int(res + step), arr) == True:
                res = int(res) + int(step)
            step = int(step) / 2
        res = int(res)
        stdout.write(str(res) + "\n")