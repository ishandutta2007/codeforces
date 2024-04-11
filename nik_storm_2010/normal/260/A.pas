var
    a,b,n,i:longint; maybe:boolean;


begin

  readln(a,b,n); maybe:=false;
  for i:=0 to 9 do
    if (a*10+i) mod b=0 then
    begin
      a:=a*10+i; maybe:=true;
      dec(n); break;
    end;
  if maybe=false then writeln(-1) else
    begin
      write(a);
      for i:=1 to n do write(0);
    end

end.