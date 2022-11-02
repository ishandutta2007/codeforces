var
    a,kol:array[1..100000] of longint; all,n,k,l,r,i:longint;


begin

  readln(n,k); all:=0;
  for i:=1 to n do
    begin
      read(a[i]); inc(kol[a[i]]);
      if kol[a[i]]=1 then inc(all);
    end;
  if all<k then begin writeln('-1 -1'); halt; end;

  l:=1; r:=n;
  while all>=k do
    begin
      dec(kol[a[r]]); dec(r);
      if kol[a[r+1]]=0 then dec(all);
    end; inc(all);
  while all=k do
    begin
      dec(kol[a[l]]); inc(l);
      if kol[a[l-1]]<=0 then dec(all);
    end;
  writeln(l-1,' ',r+1);

end.