var
    a:array[1..3,1..3] of longint; chis,i,j:longint; maybe:boolean;


procedure proverka(var maybe:boolean);
var sum:longint;
begin
  sum:=a[1,1]+a[1,2]+a[1,3];
  if (a[2,1]+a[2,2]+a[2,3]=sum) and (a[3,1]+a[3,2]+a[3,3]=sum) and (a[1,1]+a[2,1]+a[3,1]=sum) and
     (a[1,2]+a[2,2]+a[3,2]=sum) and (a[1,3]+a[2,3]+a[3,3]=sum) and (a[1,1]+a[2,2]+a[3,3]=sum) and
     (a[1,3]+a[2,2]+a[3,1]=sum) then maybe:=true else maybe:=false;
end;


begin

  for i:=1 to 3 do
    begin
      for j:=1 to 3 do read(a[i,j]);
      readln;
    end;
  for chis:=1 to 100000 do
    begin
      a[1,1]:=chis; a[2,2]:=a[1,1]+a[1,3]-a[3,2]; a[3,3]:=a[1,1]+a[1,2]-a[2,3];
      proverka(maybe);
      if maybe then
        begin
          for i:=1 to 3 do
            begin
              for j:=1 to 3 do write(a[i,j],' ');
              writeln
            end;
          halt;
        end;
    end;

end.