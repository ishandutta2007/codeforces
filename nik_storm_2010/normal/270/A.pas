var
    t,c,i,j:longint; answer:string; ugol:extended;


begin

  readln(t);
  for i:=1 to t do
    begin
      readln(c); answer:='NO';
      for j:=3 to 5000 do
        begin
          ugol:=((j-2)*180)/j;
          if (frac(ugol)=0) and (c=trunc(ugol)) then
            begin
              answer:='YES';
              break;
            end;
        end;
      writeln(answer);
    end;

end.