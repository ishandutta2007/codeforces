var
    a,b:array[0..100000] of longint; kol,n,i,k:longint;


begin

  readln(n);
  for i:=1 to n do read(a[i]);
  a[0]:=-maxlongint; k:=0;
  for i:=1 to n do
    if a[i]=a[k] then inc(b[k]) else
    begin
      inc(k); a[k]:=a[i]; b[k]:=1;
    end;
  a[k+1]:=maxlongint; kol:=0; i:=1;
  while i<=k do
    begin
      if b[i]=1 then begin inc(kol); inc(i); end else
      begin
        if b[i] mod 2=1 then inc(kol);
        a[i]:=a[i]+1; b[i]:=b[i] div 2;
        if a[i+1]=a[i] then begin b[i+1]:=b[i+1]+b[i]; inc(i); end;
      end;
    end;
  writeln(a[k]-kol+1);

end.