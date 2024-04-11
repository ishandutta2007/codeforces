var
    a:array[1..100] of longint; ans,n,d,l,i,j:longint;


begin

  readln(n,d,l);
  for i:=1 to n do
    if i mod 2=1 then a[i]:=1 else a[i]:=l;
  ans:=a[n];
  for i:=n-1 downto 1 do ans:=a[i]-ans;
  if (ans=d) or (l=1) then
    begin
      if (ans=d) then
        begin
          for j:=1 to n do write(a[j],' '); halt;
        end;
    end
      else
    begin
      i:=1;
      while i<=n do
        begin
          if a[i]=l then
            begin
              inc(i,2);
              if i>n then break;
            end;
          inc(a[i]); inc(ans);
          if ans=d then begin for j:=1 to n do write(a[j],' '); halt; end;
        end;
      if n mod 2=0 then i:=n else i:=n-1;
      while i>0 do
        begin
          if a[i]=1 then
            begin
              dec(i,2);
              if i<=0 then break;
            end;
          dec(a[i]); inc(ans);
          if ans=d then begin for j:=1 to n do write(a[j],' '); halt; end;
        end;
    end;
  writeln(-1);

end.