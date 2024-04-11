s := File standardInput readLine
a := File standardInput readLine
b := File standardInput readLine
n := s split at(0) asNumber
m := s split at(1) asNumber

kolx := 0
a := a split
a := a slice(1)
for (i,0,((a size) -1),
a atPut(i, a at(i) asNumber)
)
a append(0)
a append(n+1)
sz := a size
for (i,0,sz-1,
    for (j,i,sz-1,
       if ((a at(j)) < (a at(i)),
          t := a at(i)
          a := a atPut(i, a at(j))
          a := a atPut(j, t)
       )
    )
)
for (i,0,sz-2,
   tmp := ((a at(i+1)) - (a at(i)) - 1)
   kolx := (kolx + (if (tmp>0,1,0)))
)

a:=b

koly := 0
a := a split
a := a slice(1)
for (i,0,((a size) -1),
a atPut(i, a at(i) asNumber)
)
a append(0)
a append(m+1)
sz := a size
for (i,0,sz-1,
    for (j,i,sz-1,
       if ((a at(i)) > (a at(j)),
          t := a at(i)
          a := a atPut(i, a at(j))
          a := a atPut(j, t)
       )
    )
)
for (i,0,sz-2,
   tmp := ((a at(i+1)) - (a at(i)) - 1)
   koly := (koly + (if (tmp>0,1,0)))
)


(koly*kolx) print