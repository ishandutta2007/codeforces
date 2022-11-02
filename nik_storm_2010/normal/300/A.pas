var
    a:array[1..100] of longint; used:array[1..100] of boolean; kol,num,n,i:longint;


begin

  readln(n); kol:=0; num:=0;
  for i:=1 to n do
  begin
    read(a[i]);
    if a[i]<0 then inc(kol);
    if a[i]=0 then inc(num);
  end;
  for i:=1 to n do
    if a[i]<0 then
    begin
      writeln(1,' ',a[i]); used[i]:=true;
      break;
    end;;
  if kol+num=n then
    begin
      write(2); num:=0;
      for i:=1 to n do
        if (a[i]<0) and (used[i]=false) then
        begin
          write(' ',a[i]); used[i]:=true; inc(num);
          if num=2 then break;
        end;
      writeln;
    end
      else
    begin
      for i:=1 to n do
        if a[i]>0 then
        begin
          writeln(1,' ',a[i]); used[i]:=true;
          break;
        end;
    end;
  kol:=0;
  for i:=1 to n do if used[i]=false then inc(kol);
  write(kol);
  for i:=1 to n do
    if used[i]=false then write(' ',a[i]);

end.