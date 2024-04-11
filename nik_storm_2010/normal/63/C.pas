uses math;
 var
    a:array[1..6,1..10] of longint; kol:array[1..2,0..9] of longint; used:array[0..9] of boolean;
     tek,last:array[1..4] of longint; n,i,j,code,ans:longint; c:char;



procedure check(var ans:boolean);
  var i,j,k1,k2:longint;
begin
  for i:=1 to n do
    begin
      for j:=0 to 9 do begin kol[1,j]:=0; kol[2,j]:=0; end;

      k1:=0; k2:=0;
      for j:=1 to 4 do
        begin
          if a[j,i] = tek[j] then inc(k1)
            else
            begin
              inc(kol[1,a[j,i]]);
              inc(kol[2,tek[j]]);
            end;
        end;
      for j:=0 to 9 do inc(k2,min(kol[1,j],kol[2,j]));

      if (k1=a[5,i]) and (k2=a[6,i]) then ans:=true
        else
        begin
          ans:=false;
          exit;
        end;
    end;
end;


procedure rec(t:longint);
  var i:longint; may:boolean;
begin
  if t=5 then
    begin
      check(may);
      if may=true then
        begin
          inc(ans);
          for i:=1 to 4 do last[i]:=tek[i];
        end;
    end
      else
    begin
      for i:=0 to 9 do
        if used[i]=false then
          begin
            tek[t]:=i; used[i]:=true;
              rec(t+1);
            tek[t]:=0; used[i]:=false;
          end;
    end;
end;


begin

  readln(n);
    for i:=1 to n do
      begin
        for j:=1 to 4 do begin read(c); val(c,a[j,i],code); end;
        readln(a[5,i],a[6,i]);
      end;
  ans:=0; rec(1);

  if ans=0 then
    begin
      writeln('Incorrect data');
    end
      else
    begin
      if ans=1 then
        begin
          for i:=1 to 4 do write(last[i]);
        end
          else
        begin
          writeln('Need more data');
        end;
    end;

end.