n = int(input().strip())
data = list(map(int, input().split()))

data.sort()

def search(d):
    idx = len(d) - 1
    while idx >= 0:
        cnt = 1
        idx -= 1
        while idx >= 0 and d[idx] == d[idx+1]:
            cnt += 1
            idx -= 1
        if cnt % 2 == 1:
            return "Conan"

    return "Agasa"

print (search(data))