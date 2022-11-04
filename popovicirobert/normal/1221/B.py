if __name__ == "__main__":

    n = int(input())
    for i in range(n):
        str = ""
        for j in range(n):
            if (i + j) % 2 == 0:
                str = str + "W"
            else:
                str = str + "B"
        print(str)