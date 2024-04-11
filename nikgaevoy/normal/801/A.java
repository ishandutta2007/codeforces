import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String str = scanner.nextLine();

        String parts[] = str.split("VK");

        int cnt = 0;

        for (int i = 1; i < str.length(); i++)
            if (str.substring(i - 1, i + 1).equals("VK"))
                cnt++;

        for (int i = 0; i < parts.length; i++) {
            for (int j = 1; j < parts[i].length(); j++) {
                if (parts[i].charAt(j) == 'K' || parts[i].charAt(j - 1) == 'V') {
                    cnt++;
                    i = parts.length;

                    break;
                }
            }
        }

        System.out.println(cnt);
    }
}