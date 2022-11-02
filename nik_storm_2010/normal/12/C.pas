uses
    math;
var
    a: array[1..2,1..100] of longint;
    s: array[1..100] of string;
    kol,n,m,i,j,nom: longint;
    maxx,minn: int64;
    st: string;


procedure qsort(nom,l,r:longint);
var i,j,w,d:longint;
 begin
  i:=l;
   j:=r;
    d:=a[nom,(i+j) div 2];
     while i<=j do
      begin
       while a[nom,i]<d do inc(i);
       while a[nom,j]>d do dec(j);
        if i<=j
         then
          begin
           w:=a[nom,i];
            a[nom,i]:=a[nom,j];
             a[nom,j]:=w;
              inc(i);
               dec(j);
          end;
      end;
   if i<r then qsort(nom,i,r);
  if l<j then qsort(nom,l,j);
 end;


Begin

  kol:=0;
   readln(n,m);
    for i:=1 to n do
     read(a[1,i]);
    readln;
   for i:=1 to m do
    begin
     readln(st);
      nom:=kol+1;
       for j:=1 to kol do
        if s[j] = st
         then
          begin
           nom:=j;
            break;
          end;
       s[nom]:=st;
      inc(a[2,nom]);
     kol:=max(nom,kol);
    end;

  qsort(1,1,n);
   qsort(2,1,kol);

  maxx:=0;
   minn:=0;
    for i:=kol downto 1 do
     begin
      minn:=minn+(a[1,kol-i+1]*a[2,i]);
      maxx:=maxx+(a[1,n-kol+i]*a[2,i]);
     end;
  writeln(minn,' ',maxx);

End.