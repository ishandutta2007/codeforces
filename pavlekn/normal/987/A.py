def main():
    n = int(input())
    a = {}
    a["purple"] = "Power"
    a["green"] = "Time"
    a["blue"] = "Space"
    a["orange"] = "Soul"
    a["red"] = "Reality"
    a["yellow"] = "Mind"
    b = []
    for i in range(n):
        s = input()
        b.append(s)
    print(6 - n)
    for key in a:
        if (key not in b):
            print(a[key])
main()